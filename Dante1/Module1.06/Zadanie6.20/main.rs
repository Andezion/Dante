fn main() {
    let mut input: String = String::new();

    println!("Enter");
    let mut matrixA: [[i32; 5]; 5] = [[0; 5]; 5];
    let mut vectorA: [i32; 5] = [0; 5];
    for i in 0..5 {
        for j in 0..5 {
            std::io::stdin().read_line(&mut input).expect("Error");
            matrixA[i][j] = input.trim().parse().expect("err");

            input.clear();
        }
    }

    println!("Enter");
    let mut matrixB: [[i32; 5]; 5] = [[0; 5]; 5];
    let mut vectorB: [i32; 5] = [0; 5];
    for i in 0..5 {
        for j in 0..5 {
            std::io::stdin().read_line(&mut input).expect("Error");
            matrixB[i][j] = input.trim().parse().expect("err");

            input.clear();
        }
    }

    for i in 0..5 {
        let mut sum1: i32 = 0;
        let mut sum2: i32 = 0;
        for j in 0..5 {
            sum1 = sum1 + matrixA[j][i];
            sum2 = sum2 + matrixB[j][i];
        }
        vectorA[i] = sum1;
        vectorB[i] = sum2;
    }

    for i in 0..5 {
        for j in 0..5 {
            if vectorA[j] >= vectorB[j]
            {
                println!("{} ", matrixA[i][j]);
            }
            else
            {
                println!("{} ", matrixB[i][j]);
            }
        }
        println!();
    }

}
