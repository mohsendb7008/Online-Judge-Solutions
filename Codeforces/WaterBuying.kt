object WaterBuying {
    fun solve(){
        repeat(readLine()!!.toInt()){
            val(n, a, b) = readLine()!!.split(" ").map { it.toLong() }
            println(if(2 * a <= b) n * a else (n / 2) * b + (n % 2) * a)
        }
    }
}

fun main() = WaterBuying.solve()