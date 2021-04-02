fun main() = readLine()!!.split(" ").map { it.toInt() }.sorted().let {
    print("${it[3] - it[2]} ${it[3] - it[1]} ${it[3] - it[0]}")
}