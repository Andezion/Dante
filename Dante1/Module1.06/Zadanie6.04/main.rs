use rand::random_range;

fn print(array: & [[i32; 4]; 4])
{
    for i in 0..4
    {
        for j in 0..4
        {
            print!("{} ", array[i][j]);
        }
        println!();
    }
    println!();
}

fn main()
{
    let mut array_a:[[i32; 4]; 4] = [[0; 4]; 4];
    let mut array_b:[[i32; 4]; 4] = [[0; 4]; 4];
    let mut array_c:[[i32; 4]; 4] = [[0; 4]; 4];
    
    for i in 0..4
    {
        for j in 0..4
        {
            let for_a: i32 = random_range(0..10);
            let for_b: i32 = random_range(0..10);
            let for_c: i32 = random_range(0..10);
            
            array_a[i][j] = for_a;
            array_b[i][j] = for_b;
            array_c[i][j] = for_c;
        }
    }
    
    print(& array_a);
    print(& array_b);
    print(& array_c);
}
