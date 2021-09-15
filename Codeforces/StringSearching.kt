val strings = HashMap<String, Int>()

fun main() {
    val(n, m) = readLine()!!.split(" ").map { it.toInt() }
    repeat(n) {
        strings[readLine()!!] = it
    }
    val q = readLine()!!.toInt()
    repeat(q) {
        val indices = HashSet<Int>()
        val s = readLine()!!
        for(i in 0..m) {
            val t = s.removeRange(i..i)
            if (strings.containsKey(t))
                indices.add(strings[t]!!)
        }
        println(indices.size)
    }
}