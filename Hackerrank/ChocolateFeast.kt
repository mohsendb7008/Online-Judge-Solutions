object ChocolateFeast {
    fun solve(){
        val(n, c, m) = readLine()!!.split(" ").map { it.toLong() }
        var(ans, wrappers) = n / c to n / c
        while(wrappers >= m){
            ans += wrappers / m
            wrappers = wrappers / m + wrappers % m
        }
        println(ans)
    }
}

fun main() = repeat(readLine()!!.toInt()){ ChocolateFeast.solve() }
