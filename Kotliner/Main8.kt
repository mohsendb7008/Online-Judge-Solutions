fun main() {
    var r = readln().split(" ")[1].toLong()
    println(readln().split(" ").map { it.toLong() }.sorted().fold(0) { num, c ->
        if (r >= c) {
            r -= c
            num + 1
        }
        else
            num
    })
}