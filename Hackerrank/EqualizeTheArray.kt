object EqualizeTheArraySolver {
    fun solve() =
        println(readLine()!!.toInt() -
                readLine()!!.split(" ").map {
                    it.toInt()
                }.groupingBy {
                    it
                }.eachCount().maxBy {
                    it.value
                }!!.value)
}

fun main() = EqualizeTheArraySolver.solve()