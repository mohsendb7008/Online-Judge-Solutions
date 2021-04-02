fun main() {
    val(n, k) = readLine()!!.split(" ").map{ it.toInt() }
    var ans = n
    repeat(k){
        if(ans % 10 == 0)
            ans /= 10
        else
            ans--
    }
    println(ans)
}