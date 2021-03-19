object FromZeroToY{
    fun solve(){
        repeat(readLine()!!.toInt()){
            var(x, y) = readLine()!!.split(" ").map { it.toLong() }
            var ans = 0L
            for(i in 9 downTo 0){
                val tp = ("$x${"0".repeat(i)}").toLong()
                ans += y / tp
                y %= tp
            }
            println(ans+y)
        }
    }
}

fun main() = FromZeroToY.solve()