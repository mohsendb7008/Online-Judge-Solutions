object ElectronicsShopSolver {
    fun solve(){
        val(budget, _, _) = readLine()!!.split(" ").map { it.toInt() }
        val tmp = readLine()!!.split(" ")
        println(readLine()!!.split(" ").flatMap { it1 ->
            tmp.map { it2 ->
                it1.toInt() + it2.toInt()
            }
        }.filter {
                it <= budget
        }.max() ?: -1)
    }
}

fun main() = ElectronicsShopSolver.solve()
