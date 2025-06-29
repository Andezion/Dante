fn main() 
{
    let mut array:[[i32; 11]; 11] = [[0; 11]; 11];
    
    for i in 0..11
    {
        for j in 0..11
        {
            array[i][j] = (i * j) as i32;
            print!("{:4} ", array[i][j]);
        }
        println!();
    }
}
