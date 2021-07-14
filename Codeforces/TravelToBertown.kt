import java.lang.Integer.max

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, k) = readLine()!!.split(" ").map { it.toInt() }
        var ans = 0
        repeat(n) {
            val(l, r) = readLine()!!.split(" ").map { it.toInt() }
            if(k in l..r)
                ans = max(ans, r - k + 1)
        }
        println(ans)
    }
}