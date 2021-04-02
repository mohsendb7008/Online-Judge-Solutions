// A Favourable Ending

val input = HashMap<Int, List<String>>()
val memo = HashMap<Int, Long>()

fun dp(i: Int): Long{
    if(i in memo)
        return memo[i]!!
    val data = input[i]!!
    if(data.size == 1) {
        memo[i] = if (data[0] == "favourably") 1L else 0L
        return memo[i]!!
    }
    var ans = 0L
    data.forEach {
        ans += dp(it.toInt())
    }
    memo[i] = ans
    return ans
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        input.clear()
        repeat(n){
            val line = readLine()!!.split(" ")
            input[line[0].toInt()] = line.subList(1, line.size)
        }
        memo.clear()
        println(dp(1))
    }
}