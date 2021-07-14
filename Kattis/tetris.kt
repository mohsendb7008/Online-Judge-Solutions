// Tetris

data class Tetris(val floor: List<Int>)

val groups = listOf(
    emptyList(),
    listOf(Tetris(listOf(0)), Tetris(listOf(0, 0, 0, 0))),
    listOf(Tetris(listOf(0, 0))),
    listOf(Tetris(listOf(0, 0, -1)), Tetris(listOf(-1, 0))),
    listOf(Tetris(listOf(-1, 0, 0)), Tetris(listOf(0, -1))),
    listOf(Tetris(listOf(0, 0, 0)), Tetris(listOf(0, -1)), Tetris(listOf(-1, 0, -1)), Tetris(listOf(-1, 0))),
    listOf(Tetris(listOf(0, 0, 0)), Tetris(listOf(0, 0)), Tetris(listOf(0, -1, -1)), Tetris(listOf(-2, 0))),
    listOf(Tetris(listOf(0, 0, 0)), Tetris(listOf(0, -2)), Tetris(listOf(-1, -1, 0)), Tetris(listOf(0, 0)))
)

fun main() {
    val (C, P) = readLine()!!.split(" ").map { it.toInt() }
    val h = readLine()!!.split(" ").map { it.toInt() }
    var ans = 0
    for (i in 0 until C) {
        groups[P].forEach { tetris ->
            if(i + tetris.floor.size <= C) {
                for(j in i + 1 until i + tetris.floor.size)
                    if(h[i] + tetris.floor[0] != h[j] + tetris.floor[j - i])
                        return@forEach
                ans++
            }
        }
    }
    println(ans)
}