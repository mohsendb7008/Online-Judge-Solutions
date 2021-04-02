object FileName {
    fun solve() =
        println((readLine() to readLine()!!.split(Regex("[^x]")).filter { it.startsWith("xxx") }.sumBy { it.length - 2 }).second)
}

fun main() = FileName.solve()