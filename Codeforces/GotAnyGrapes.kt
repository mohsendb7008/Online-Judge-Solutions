fun main() {
    val(x, y, z) = readLine()!!.split(" ").map { it.toInt() }
    var(g, p, b) = readLine()!!.split(" ").map { it.toInt() }
    if(x > g) {
        println("NO")
        return
    }
    g -= x
    if(y > g + p){
        println("NO")
        return
    }
    p -= y
    if(z > g + p + b){
        println("NO")
        return
    }
    println("YES")
}