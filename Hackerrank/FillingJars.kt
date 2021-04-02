object FillingJars {
    fun solve(){
        val(n, m) = readLine()!!.split(" ").map { it.toInt() }
        println(Array(m){ readLine()!!.split(" ").map { it.toDouble() } }.toMutableList().sumByDouble {
            it[2] * (it[1] - it[0] + 1)
        }.toLong() / n)
    }
}

fun main() = FillingJars.solve()