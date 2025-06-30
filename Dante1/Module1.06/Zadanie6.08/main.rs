fn main()
{
    let mut input: String = String::new();
    let mut array:[[i32; 15]; 15] = [[0; 15]; 15];
    let mut result:[i32; 32] = [0; 32];
    
    println!("Enter: ");
    for i in 0..15
    {
        for j in 0..15
        {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect string input");
            array[i][j] = input.trim().parse().expect("Incorrect number");
            
            if array[i][j] < 0 || array[i][j] >= 30
            {
                panic!("Incorrect range");
            }
            
            result[array[i][j] as usize] += 1;
        }
    }
    
    for i in 0..15
    {
        for j in 0..15
        {
            print!("{:2} ", result[array[i][j] as usize]);
        }
        println!();
    }
}
