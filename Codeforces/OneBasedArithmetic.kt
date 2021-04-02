import kotlin.math.min

val ones = ArrayList<Long>()

fun lowerBound(n: Long): Int{
    var(lo, hi) = 0 to ones.size - 1
    while(lo < hi){
        val mid = (lo + hi) / 2 + (lo + hi) % 2
        if(ones[mid] < n)
            lo = mid
        else
            hi = mid - 1
    }
    return lo
}

val memo = HashMap<Long, Long>()

fun rec(n: Long): Long{
    if(n in memo)
        return memo[n]!!
    val bs = lowerBound(n)
    if(ones[bs + 1] == n){
        memo[n] = (bs + 2).toLong()
        return (bs + 2).toLong()
    }
    var ans = Long.MAX_VALUE
    if(n - ones[bs] < n)
        ans = min(ans, rec(n - ones[bs]) + bs + 1)
    if(ones[bs + 1] - n < n)
        ans = min(ans, rec(ones[bs + 1] - n) + bs + 2)
    memo[n] = ans
    return ans
}

fun main() {
    val n = readLine()!!.toLong()
    for(i in 1..16)
        ones.add("1".repeat(i).toLong())
    memo[0L] = 0L
    for(i in 1L..6L)
        memo[i] = i
    for(i in 7L..11L)
        memo[i] = 13-i
    println(rec(n))
}