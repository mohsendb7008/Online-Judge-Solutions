import java.math.BigInteger

// The Embarrassed Cryptographer

val primeCheck = BooleanArray(1000003){true}
val primes = ArrayList<Int>()

fun main() {
    for(i in 2 until 1000000)
        if(primeCheck[i]){
            primes.add(i)
            for(j in i.toLong() * i until 1000000L step i.toLong())
                primeCheck[j.toInt()] = false
        }
    while(true){
        val line = readLine()!!.split(" ")
        if(line[0] == "0" && line[1] == "0")
            break
        val k = BigInteger(line[0])
        val l = line[1].toInt()
        var found = false
        for(prime in primes){
            if(prime >= l)
                break
            if(k.mod(prime.toBigInteger()) == BigInteger.ZERO){
                println("BAD $prime")
                found = true
                break
            }
        }
        if(!found)
            println("GOOD")
    }
}