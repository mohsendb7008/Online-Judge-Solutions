import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max
import kotlin.math.min
import kotlin.math.sqrt

// Paintball II

fun <T> List<T>.maxOfOrNull(selector: (T) -> Double): Double? {
    if (isEmpty())
        return null
    return Collections.max(map(selector))
}

fun <T> List<T>.minOfOrNull(selector: (T) -> Double): Double? {
    if (isEmpty())
        return null
    return Collections.min(map(selector))
}

fun Int.secondExponent() = this * this

fun Int.squareRoot() = sqrt(this.toDouble())

infix fun Pair<Double, Double>.intersect(that: Pair<Double, Double>) = max(this.first, that.first) to min(this.second, that.second)

data class Location<T>(val x: T, val y: T)

infix fun Location<Int>.distanceSquared(that: Location<Int>) =
    (this.x - that.x).secondExponent() + (this.y - that.y).secondExponent()

data class Opponent(val location: Location<Int>, val firingRadius: Int, val id: Int = LAST_ID++) {

    companion object {

        private var LAST_ID = 0

    }

}

infix fun Opponent.intersects(that: Opponent) =
    this.location distanceSquared that.location < (this.firingRadius + that.firingRadius).secondExponent()

infix fun Opponent.intersectionWithVerticalLine(x: Int): Pair<Double, Double> {
    val delta = (this.firingRadius.secondExponent() - (this.location.x - x).secondExponent()).squareRoot()
    return this.location.y.toDouble() - delta to this.location.y.toDouble() + delta
}

class IntervalFactory(start: Double, end: Double) {

    private val intervals = mutableListOf(start to end)

    fun removeInterval(s2: Double, e2: Double) {
        val toDelete = mutableListOf<Int>()
        val toAdd = mutableListOf<Pair<Double, Double>>()
        intervals.forEachIndexed { index, it ->
            val (s1, e1) = it
            if (s2 >= e1 || e2 <= s1) {
                return@forEachIndexed
            }
            toDelete.add(index)
            if (s1 <= s2) {
                toAdd.add(s1 to s2)
            }
            if (e2 <= e1) {
                toAdd.add(e2 to e1)
            }
        }
        toDelete.reversed().forEach {
            intervals.removeAt(it)
        }
        intervals.addAll(toAdd)
    }

    fun removeInterval(interval: Pair<Double, Double>) = removeInterval(interval.first, interval.second)

    fun getIntervals() = intervals.toList().sortedBy { it.first }

}

class PaintballGraph(private val opponents: List<Opponent>) {

    private val adjacents = Array(opponents.size) { ArrayList<Int>() }

    init {

        opponents.forEachIndexed { firstIndex, first ->
            opponents.forEachIndexed { secondIndex, second ->
                if (firstIndex != secondIndex && first intersects second) {
                    adjacents[firstIndex].add(secondIndex)
                }
            }
        }

    }

    fun canReach(
        sourceCondition: (Opponent) -> Boolean, destinationCondition: (Opponent) -> Boolean,
        sourceOpponents: MutableList<Opponent>? = null, destinationOpponents: MutableList<Opponent>? = null
    ): Boolean {
        val depthArray = IntArray(opponents.size) { -1 }
        val bfsQueue = LinkedList<Int>()
        opponents.withIndex().filter { sourceCondition(it.value) }.forEach {
            depthArray[it.index] = 0
            bfsQueue.add(it.index)
            sourceOpponents?.apply {
                add(it.value)
            }
        }
        var reachable = false
        while (bfsQueue.isNotEmpty()) {
            val front = bfsQueue.first
            if (destinationCondition(opponents[front])) {
                reachable = true
                destinationOpponents?.apply {
                    add(opponents[front])
                }
            }
            bfsQueue.removeFirst()
            adjacents[front].filter { depthArray[it] == -1 }.forEach {
                depthArray[it] = depthArray[front] + 1
                bfsQueue.add(it)
            }
        }
        return reachable
    }

    fun canReach(
        source: Opponent, destinationCondition: (Opponent) -> Boolean,
        sourceOpponents: MutableList<Opponent>? = null, destinationOpponents: MutableList<Opponent>? = null
    ) = canReach({ opponent -> opponent.id == source.id }, destinationCondition, sourceOpponents, destinationOpponents)

    companion object {

        fun conditionIntersectsVerticalLine(x: Int): (Opponent) -> Boolean = {
            it.firingRadius.secondExponent() > (it.location.x - x).secondExponent()
        }

        fun conditionIntersectsHorizontalLine(y: Int): (Opponent) -> Boolean = {
            it.firingRadius.secondExponent() > (it.location.y - y).secondExponent()
        }

    }


}

sealed class PaintballSolution

class PossibleSolution(val enter: Location<Double>, val exit: Location<Double>) : PaintballSolution()

object ImpossibleSolution : PaintballSolution()

class PaintballSolver(private val opponents: List<Opponent>) {

    private val graph = PaintballGraph(opponents)

    companion object {

        private const val X_RANGE_START = 0

        private const val X_RANGE_END = 1000

        private const val Y_RANGE_START = 0

        private const val Y_RANGE_END = 1000

        val conditionWestLine = PaintballGraph.conditionIntersectsVerticalLine(X_RANGE_START)

        val conditionEastLine = PaintballGraph.conditionIntersectsVerticalLine(X_RANGE_END)

        val conditionSouthLine = PaintballGraph.conditionIntersectsHorizontalLine(Y_RANGE_START)

        val conditionNorthLine = PaintballGraph.conditionIntersectsHorizontalLine(Y_RANGE_END)

    }

    fun solve(): PaintballSolution {

        if (graph.canReach(conditionSouthLine, conditionNorthLine)) {
            return ImpossibleSolution
        }

        val westFactory = IntervalFactory(Y_RANGE_START.toDouble(), Y_RANGE_END.toDouble())
        val eastFactory = IntervalFactory(Y_RANGE_START.toDouble(), Y_RANGE_END.toDouble())

        val westOpponents = opponents.filter(conditionWestLine)
        westOpponents.forEach { opponent ->
            val intersection = opponent intersectionWithVerticalLine X_RANGE_START
            westFactory.removeInterval(intersection)
            if (graph.canReach(opponent, conditionNorthLine)) {
                westFactory.removeInterval(intersection.first, Y_RANGE_END.toDouble() + 1)
            }
            if (graph.canReach(opponent, conditionSouthLine)) {
                westFactory.removeInterval(Y_RANGE_START.toDouble() - 1, intersection.second)
            }
        }

        val eastOpponents = opponents.filter(conditionEastLine)
        eastOpponents.forEach { opponent ->
            val intersection = opponent intersectionWithVerticalLine X_RANGE_END
            eastFactory.removeInterval(intersection)
            if (graph.canReach(opponent, conditionNorthLine)) {
                eastFactory.removeInterval(intersection.first, Y_RANGE_END.toDouble() + 1)
            }
            if (graph.canReach(opponent, conditionSouthLine)) {
                eastFactory.removeInterval(Y_RANGE_START.toDouble() - 1, intersection.second)
            }
        }

        val westIntervals = westFactory.getIntervals()
        val eastIntervals = eastFactory.getIntervals()

        val limitations = mutableListOf<Pair<Pair<Double, Double>, Pair<Double, Double>>>()
        westOpponents.forEach { opponent ->
            val buffer = mutableListOf<Opponent>()
            if (graph.canReach(opponent, conditionEastLine, destinationOpponents = buffer)) {
                val intersection = opponent intersectionWithVerticalLine X_RANGE_START
                val start = buffer.minOfOrNull { (it intersectionWithVerticalLine X_RANGE_END).first } !!
                val end = buffer.maxOfOrNull { (it intersectionWithVerticalLine X_RANGE_END).second } !!
                limitations.add(intersection to (start to end))
            }
        }

        westIntervals.sortedByDescending { it.second }.forEach { west ->
            var(lowerBound, upperBound) = Y_RANGE_START.toDouble() to Y_RANGE_END.toDouble()
            limitations.forEach { limitation ->
                val leftSide = limitation.first
                val rightSide = limitation.second
                if (leftSide.second <= west.first) {
                    lowerBound = max(lowerBound, rightSide.second)
                }
                if (leftSide.first >= west.second) {
                    upperBound = min(upperBound, rightSide.first)
                }
            }
            eastIntervals.sortedByDescending { it.second }.forEach { east ->
                val intersection = east intersect (lowerBound to upperBound)
                if (intersection.first <= intersection.second) {
                    return PossibleSolution(Location(X_RANGE_START.toDouble(), west.second), Location(X_RANGE_END.toDouble(), east.second))
                }
            }
        }

        return ImpossibleSolution
    }

}

fun main() {
    val n = readLine()!!.toInt()
    val opponents = ArrayList<Opponent>()
    repeat(n) {
        val (x, y, r) = readLine()!!.split(" ").map { it.toInt() }
        opponents.add(Opponent(Location(x, y), r))
    }
    val solver = PaintballSolver(opponents)
    when (val answer = solver.solve()) {
        is PossibleSolution -> {
            val enter = answer.enter
            val exit = answer.exit
            System.out.printf("%.2f %.2f %.2f %.2f\n", enter.x, enter.y, exit.x, exit.y)
        }
        is ImpossibleSolution -> {
            println("IMPOSSIBLE")
        }
    }
}
