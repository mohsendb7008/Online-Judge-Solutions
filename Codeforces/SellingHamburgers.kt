import kotlin.math.max

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        val hm = readLine()!!.split(" ").map { it.toLong() }.toMutableList()
        hm.sort()
        var ans = 0L
        for(i in 0 until n)
            ans = max(ans, hm[i] * (n - i))
        println(ans)
    }
}