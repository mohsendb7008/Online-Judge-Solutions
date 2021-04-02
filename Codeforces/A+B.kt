fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(A, B) = readLine()!!.split(" ").map { it.toInt() }
        println(A + B)
    }
}