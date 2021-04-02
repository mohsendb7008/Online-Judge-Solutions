import kotlin.math.min

// Initials

const val inf = Int.MAX_VALUE

val unix = ArrayList<Pair<String, Int>>()
val partial = Array(1003){Array(83){""}}
val dp = Array(1003){IntArray(83)}

fun Pair<String, Int>.make(j: Int): String{
    var result = ""
    var cnt = j - 2
    result += first[0]
    for(i in 1 until second){
        if(cnt == 0)
            break
        result += first[i]
        cnt--
    }
    result += first[second]
    for(i in second + 1 until first.length){
        if(cnt == 0)
            break
        result += first[i]
        cnt--
    }
    return result
}

fun main(){
    val n = readLine()!!.toInt()
    for(i in 0 until n){
        val(fn, ln) = readLine()!!.split(" ")
        unix.add(ln.toLowerCase() + fn.toLowerCase() to ln.length)
    }
    unix.sortBy { it.first }
    for(i in 0 until n)
        for(j in 2..unix[i].first.length)
            partial[i][j] = unix[i].make(j)
    for(j in 2..unix[n-1].first.length)
        dp[n-1][j] = j-2
    for(i in n-2 downTo 0)
        for(j in 2..unix[i].first.length){
            dp[i][j] = inf
            for(k in 2..unix[i+1].first.length)
                if(dp[i+1][k] != inf && partial[i][j] < partial[i+1][k])
                    dp[i][j] = min(dp[i][j], j-2 + dp[i+1][k])
        }
    var ans = inf
    for(j in 2..unix[0].first.length)
        ans = min(ans, dp[0][j])
    println(ans)
}