import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*

fun solveYellowCards(a1: Int, a2: Int, k1: Int, k2: Int, n: Int): Int {
    val fg = min(n / k1, a1)
    val sg = min(max(n - fg * k1, 0) / k2, a2)
    return fg + sg
}

fun main() {
    val a1 = readLine()!!.toInt()
    val a2 = readLine()!!.toInt()
    val k1 = readLine()!!.toInt()
    val k2 = readLine()!!.toInt()
    val n = readLine()!!.toInt()
    val ansMAx = if (k1 < k2) solveYellowCards(a1, a2, k1, k2, n) else solveYellowCards(a2, a1, k2, k1, n)
    val priorityQueue = PriorityQueue<Int>()
    repeat(a1) {
        priorityQueue.add(-k1)
    }
    repeat(a2) {
        priorityQueue.add(-k2)
    }
    var ansMin = 0
    repeat(n) {
        val top = priorityQueue.poll()
        if (top < -1) {
            priorityQueue.add(top + 1)
        }
        else {
            ansMin++
        }
    }
    println("$ansMin $ansMAx")
}