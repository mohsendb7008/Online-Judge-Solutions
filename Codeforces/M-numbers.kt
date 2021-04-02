fun feasible(m: Int): Boolean{
    var num = m
    while (num != 1){
        num /= when{
            num % 2 == 0 -> 2
            num % 3 == 0 -> 3
            num % 5 == 0 -> 5
            num % 7 == 0 -> 7
            else -> return false
        }
    }
    return true
}

val memo = HashMap<Pair<Int, Int>, Long>()

fun dp(m: Int, r: Int): Long{
    if(r == 1)
        return if(m % 10 == m) 1 else 0
    if(memo.containsKey(m to r))
        return memo[m to r]!!
    var ans = 0L
    for(i in 1..9)
        if(m % i == 0)
            ans += dp(m/i, r-1)
    memo[m to r] = ans
    return ans
}

fun trace(m: Int, r: Int, k: Long, board: ArrayList<Int>){
    if(r == 1) {
        board.add(m)
        return
    }
    var kCount = k
    for(i in 1..9)
        if(m % i == 0){
            val sCount = dp(m/i, r-1)
            if(sCount < kCount){
                kCount -= sCount
            }
            else{
                board.add(i)
                trace(m/i, r-1, kCount, board)
                break
            }
        }
}

fun main() {
    val line = readLine()!!.split(" ")
    val m = line[0].toInt()
    var k = line[1].toLong()
    if(!feasible(m)) {
        println(-1)
        return
    }
    var i = 1
    while(true){
        val iCount = dp(m, i)
        if(iCount < k){
            k -= iCount
        }
        else{
            val board = ArrayList<Int>()
            trace(m, i, k, board)
            println(board.joinToString(""))
            return
        }
        i++
    }
}