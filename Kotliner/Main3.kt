fun main() {
    readln().toInt()
    val numbers = readln().split(" ").map { it.toLong() }
    var ans = numbers.max()
    var soFar = 0L
    numbers.forEach {
        soFar += it
        if (soFar > ans)
            ans = soFar
        if (soFar < 0)
            soFar = 0
    }
    println(ans)
}