fun main() {
    val(n, m) = readLine()!!.split(" ").map { it.toInt() }
    val array = readLine()!!.split(" ").map { it.toInt() }
    val mIndex = array.indexOf(m)
    val dp = IntArray(n)
    for(i in mIndex+1 until n)
        dp[i] = dp[i-1] + if(array[i] > m) 1 else 0
    for(i in mIndex-1 downTo 0)
        dp[i] = dp[i+1] + if(array[i] > m) 1 else 0
    val map = HashMap<Int, Int>()
    for(l in 0..mIndex){
        val value = 2 * dp[l] + l
        map[value] =  1 + (map[value] ?: 0)
        map[value-1] = 1 + (map[value-1] ?: 0)
    }

    var ans = 0L
    for(r in mIndex until n){
        val value = - 2 * dp[r] + r
        ans += map[value] ?: 0
    }
    println(ans)
}