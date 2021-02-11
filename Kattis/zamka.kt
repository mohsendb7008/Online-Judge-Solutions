// Zamka

fun IntProgression.zamka(X: Int) {
    forEach {
        it.takeIf { it.toString().sumBy { c -> c - '0' } == X } ?: return@forEach
        println(it)
        return@zamka
    }
}

object ZamkaSolver {
    fun solve(){
        val(L, D, X) = listOf(readLine()!!.toInt(), readLine()!!.toInt(), readLine()!!.toInt())
        (L..D).zamka(X) to (D downTo L).zamka(X)
    }
}

fun main() = ZamkaSolver.solve()