import kotlin.math.abs
import kotlin.math.min

fun main() {
    val(_, W) = readLine()!!.split(" ").map { it.toInt() }
    val ps = readLine()!!.split(" ").map { it.toInt() }.fold(ArrayList<Int>()) {
        acc, it ->
            acc.add(it + (acc.lastOrNull() ?: 0))
            acc
    }
    val(start, end) = listOf(abs(min(0, ps.min()!!)), min(W-ps.max()!!, W))
    println("${if(end >= start) end-start+1 else 0}")
}