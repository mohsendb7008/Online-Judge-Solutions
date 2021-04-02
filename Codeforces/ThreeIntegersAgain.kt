import kotlin.math.max
import kotlin.math.min

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(x, y) = readLine()!!.split(" ").map{it.toInt()}
        println("1 ${min(x, y) - 1} ${max(x, y) - min(x, y) + 1}")
    }
}