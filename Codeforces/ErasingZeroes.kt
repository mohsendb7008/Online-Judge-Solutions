fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val s = readLine()!!
        val i = s.indexOf('1')
        val j = s.lastIndexOf('1')
        println(s.filterIndexed { index, c -> index in i..j && c == '0' }.count())
    }
}