object ACMICPCTeamSolver {
    fun solve() {
        val n = readLine()!!.split(" ")[0].toInt()
        val digits = Array(n){ readLine()!! }.toMutableList()
        digits.flatMapIndexed { index, it1 ->
            digits.subList(index + 1, digits.size).map { it2 ->
                it1.zip(it2).count { it.first == '1' || it.second == '1'}
            }
        }.groupingBy {
            it
        }.eachCount().maxBy {
            it.key
        }?.let {
            println("${it.key}\n${it.value}")
        }
    }

}

fun main() = ACMICPCTeamSolver.solve()