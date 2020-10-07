import java.math.BigInteger

// The Deal of the Day

var nums = IntArray(10)
var k = 0

val dp = Array(13){ Array(13){ -BigInteger.ONE} }

fun cdp(i: Int, j: Int): BigInteger{
    if(dp[i][j] != -BigInteger.ONE)
        return dp[i][j]
    if(j == k) {
        dp[i][j] = BigInteger.ONE
        return BigInteger.ONE
    }
    if(i == 10){
        dp[i][j] = BigInteger.ZERO
        return BigInteger.ZERO
    }
    dp[i][j] = cdp(i + 1, j)
    if(nums[i] != 0)
        dp[i][j] += nums[i].toBigInteger() * cdp(i + 1, j + 1)
    return dp[i][j]
}

fun main() {
    nums = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    k = readLine()!!.toInt()
    println(cdp(0, 0))
}