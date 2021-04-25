import java.lang.Math.abs

// Relocation

fun main() {
    val(_, Q) = readLine()!!.split(" ").map { it.toInt() }
    val locations = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    for(i in 1..Q){
        val(type, A, B) = readLine()!!.split(" ").map { it.toInt() }
        if(type == 1) locations[A-1] = B else println(abs(locations[A-1] - locations[B-1]))
    }
}