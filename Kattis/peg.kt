// Peg

val adjR = listOf(-1, 1, 0, 0)
val adjC = listOf(0, 0, -1, 1)

fun main() {
    val lines = generateSequence(::readLine).toList()
    var ans = 0
    for (i in lines.indices)
        for (j in lines[i].indices)
            for (k in 0 until 4)
                if (lines[i][j] == 'o' && i + adjR[k] in lines.indices && j + adjC[k] in lines[i + adjR[k]].indices && lines[i + adjR[k]][j + adjC[k]] == 'o' && i + 2 * adjR[k] in lines.indices && j + 2 * adjC[k] in lines[i + 2 * adjR[k]].indices && lines[i + 2 * adjR[k]][j + 2 * adjC[k]] == '.')
                    ans++
    println(ans)
}