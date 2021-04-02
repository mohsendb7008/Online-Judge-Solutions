import java.math.BigInteger
import java.math.RoundingMode

// Tight words

var n = 0
var m = 0
val memo = Array(103){Array(13){BigInteger.valueOf(-1)} }

fun cMemo(i: Int, d: Int): BigInteger{
    if(memo[i][d] != BigInteger.valueOf(-1))
        return memo[i][d]
    if(i == n){
        memo[i][d] = BigInteger.ONE
        return memo[i][d]
    }
    var ans = cMemo(i+1, d)
    if(d + 1 <= m)
        ans += cMemo(i+1, d + 1)
    if(d - 1 >= 0)
        ans += cMemo(i+1, d - 1)
    memo[i][d] = ans
    return memo[i][d]
}

fun main() {
    while (true){
        val line = readLine()?.split(" ")?.map { it.toInt() } ?: break
        m = line[0]
        n = line[1]
        for(i in 0..n)
            for(j in 0..m)
                memo[i][j] = BigInteger.valueOf(-1)
        var ans = BigInteger.ZERO
        for(d in 0..m)
            ans += cMemo(1, d)
        ans *= BigInteger.valueOf(100)
        val frac = (m+1).toBigInteger().pow(n)
        println(ans.toBigDecimal().divide(frac.toBigDecimal(), 10, RoundingMode.HALF_EVEN))
    }
}