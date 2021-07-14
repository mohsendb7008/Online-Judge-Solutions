fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val(n, k) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        var like = s.count { it == '1' }
        val sweets = (0 until n).toMutableList()
        var ptr = 0
        var ans = 0
        while (like > 0) {
            ans++
            if(s[sweets[ptr]] == '1')
                like--
            sweets.removeAt(ptr)
            if(like == 0)
                break
            ptr = (ptr + k - 1) % sweets.size
        }
        println(ans)
    }
}