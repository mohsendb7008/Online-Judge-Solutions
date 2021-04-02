import kotlin.math.max

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, k) = readLine()!!.split(" ").map { it.toInt() }
        val p = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        val s = IntArray(n)
        s[0] = p[0]
        for(i in 1 until n)
            s[i] = s[i - 1] + p[i]
        var ans = 0
        for(x in 1..n){
            if(x / k == 0)
                continue
            val i = n - x
            val j = i + x / k - 1
            ans = max(ans, s[j] - if(i > 0) s[i - 1] else 0)
        }
        println(ans)
    }
}