import kotlin.math.min

fun main() {
    val(n, m, d) = readLine()!!.split(" ").map { it.toInt() }
    val woods = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
    val stick = IntArray(m)
    stick[m - 1] = n - woods[m - 1]
    for(i in m - 2 downTo 0)
        stick[i] = stick[i + 1] - woods[i]
    val ans = IntArray(n)
    var ptr = -1
    for(i in 0 until m){
        ptr = min(ptr + d, stick[i])
        for(j in 0 until woods[i])
            ans[ptr + j] = i + 1
        ptr += woods[i] - 1
    }
    if(ptr + d >= n){
        println("YES")
        println(ans.joinToString(separator = " "))
    }
    else
        println("NO")
}