fn main()
{
    let mut array:[[i32; 10]; 10] = [[0; 10]; 10];
    
    let mut sum_1: i32 = 0;
    let mut sum_2: i32 = 0;
    let mut input: String = String::new();
    
    println!("Enter: ");
    for i in 0..10
    {
        for j in 0..10
        {
            input.clear();
            
            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            array[i][j] = input.trim().parse().expect("Error while parsing the value");
            
            if (i + j) % 2 == 0
            {
                sum_1 += array[i][j];
            }
            else
            {
                sum_2 += array[i][j];
            }
        }
    }
    
    println!("Diff is: {}", sum_1 - sum_2);
}
