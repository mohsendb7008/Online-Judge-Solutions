fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(a1, b1) = readLine()!!.split(" ").map { it.toInt() }
        val(a2, b2) = readLine()!!.split(" ").map { it.toInt() }
        println(if((a1 == a2 && b1 + b2 == a1) || (a1 == b2 && b1 + a2 == a1) || (b1 == a2 && a1 + b2 == b1) || (b1 == b2 && a1 + a2 == b1)) "Yes" else "No")
    }
}