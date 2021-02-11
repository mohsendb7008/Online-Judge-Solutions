// Pet

fun IndexedValue<*>.print() = println("${index + 1} $value")

object PetSolver{
    fun solve()  = IntArray(5){readLine()!!.split(" ").map { it.toInt() }.sum()}.withIndex().maxBy { it.value }!!.print()
}

fun main() = PetSolver.solve()
