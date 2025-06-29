fn main() 
{
    let mut array:[[i32; 5]; 5] = [[0; 5]; 5];
    println!("Enter: ");
    
    let mut input: String = String::new();
    
    for i in 0..5
    {
        for j in 0..5
        {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            array[i][j] = input.trim().parse().expect("Number");
        }
    }
    
    println!();
    
    for i in 0..5
    {
        (array[i][i], array[i][4 - i]) = (array[i][4 - i], array[i][i]);
    }
    
    for i in 0..5
    {
        for j in 0..5
        {
            print!("{} ", array[i][j]);
        }
        println!();
    }
}
