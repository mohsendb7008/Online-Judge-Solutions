import kotlin.math.abs
import kotlin.math.min

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        val b = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        var(ans, best) = Int.MIN_VALUE to -1
        for(k in 0 until n){
            var curr = Int.MAX_VALUE
            for(i in 0 until n)
                curr = min(curr, abs(a[i] - b[(i + k) % n]))
            if(curr > ans){
                ans = curr
                best = k
            }
        }
        for(i in 0 until n)
            print("${(i + best) % n + 1} ")
        println()
    }
}