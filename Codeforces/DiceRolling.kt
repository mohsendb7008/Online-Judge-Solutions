import kotlin.math.min

val dp = IntArray(103)

fun main(){
    dp[0] = 0
    for(i in 1..100){
        dp[i] = Int.MAX_VALUE
        for(j in 2..7)
            if(i >= j && dp[i-j] != Int.MAX_VALUE)
                dp[i] = min(dp[i], 1 + dp[i-j])
    }
    val t = readLine()!!.toInt()
    repeat(t){
        val x = readLine()!!.toInt()
        println(dp[x])
    }
}