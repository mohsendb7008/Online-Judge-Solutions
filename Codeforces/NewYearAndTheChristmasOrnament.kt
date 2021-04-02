import kotlin.math.min

fun main() {
    val(y, b, r) = readLine()!!.split(" ").map { it.toInt() }
    val n = min(y, min(b-1, r-2))
    println(3 * n + 3)
}