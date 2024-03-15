"""
    inverse3x3(matr::Matrix)

Get the inverse of given 3x3 matrix. No additional checks are performed for efficiency. 
Matrix should not be degenerate.

# Arguments
- `matr::Matrix`: source matrix.
"""
function inverse3x3(matr::Matrix)
    det = matr[1, 1] * (matr[3, 3] * matr[2, 2] - matr[3, 2] * matr[2, 3]) - 
        matr[2, 1] * (matr[3, 3] * matr[1, 2] - matr[3, 2] * matr[1, 3]) +
        matr[3, 1] * (matr[2, 3] * matr[1, 2] - matr[2, 2] * matr[1, 3])

    invmatr = Matrix{typeof(matr[1, 1])}(undef, 3, 3)

    invmatr[1, 1] = matr[3, 3] * matr[2, 2] - matr[3, 2] * matr[2, 3]
    invmatr[1, 2] = -(matr[3, 3] * matr[1, 2] - matr[3, 2] * matr[1, 3])
    invmatr[1, 3] = matr[2, 3] * matr[1, 2] - matr[2, 2] * matr[1, 3]

    invmatr[2, 1] = -(matr[3, 3] * matr[2, 1] - matr[3, 1] * matr[2, 3])
    invmatr[2, 2] = matr[3, 3] * matr[1, 1] - matr[3, 1] * matr[1, 3]
    invmatr[2, 3] = -(matr[2, 3] * matr[1, 1] - matr[2, 1] * matr[1, 3])

    invmatr[3, 1] = matr[3, 2] * matr[2, 1] - matr[3, 1] * matr[2, 2]
    invmatr[3, 2] = -(matr[3, 2] * matr[1, 1] - matr[3, 1] * matr[1, 2])
    invmatr[3, 3] = matr[2, 2] * matr[1, 1] - matr[2, 1] * matr[1, 2]

    invmatr .*= (1 / det)

    return invmatr 
end

"""
    inverse3x3_test(testcnt::Int)

Generate `testcnt` tests and perform it. Method outputs result of each test to REPL.

# Arguments
- `testcnt::Int`: number of tests.
"""
function inverse3x3_test(testcnt::Int)
    @info "Testing..."
    for testix in 1:testcnt
        print("Matrix #", testix, " --- ")
        testmatr = rand(3, 3) .* 100
        algoanswer = inverse3x3(testmatr)
        realanswer = inv(testmatr)
        if algoanswer ≈ realanswer
            println("passed")
        else
            println("failed")
        end
    end
end

"""
    compare_execution_time(measurementscnt::Int)

Compare measurement time of inverse matrix calculation by `inverse3x3()` and out-of-box 
Julia method `inv()`. For each way this method performes `measurementscnt` calculations and
compares total times.

# Arguments
- `measurementscnt::Int`: count of measurements.
"""
function compare_execution_time(measurementscnt::Int)
    matr = rand(3, 3) .* 100

    # Using inv()
    inv_total_time = 0
    for measurementix in 1:measurementscnt
        inv_time = @elapsed begin
            invmatr = inv(matr)
        end
        inv_total_time += inv_time
    end

    # Using inverse3x3()
    inverse3x3_total_time = 0
    for measurementix in 1:measurementscnt
        inverse3x3_time = @elapsed begin
            invmatr = inverse3x3(matr)
        end
        inverse3x3_total_time += inverse3x3_time
    end

    @info "Out-of-box Julia inv()"
    println(inv_total_time)

    @info "Explicit inverse3x3()"
    println(inverse3x3_total_time)
end

# inverse3x3_test(100)
# compare_execution_time(10000)
