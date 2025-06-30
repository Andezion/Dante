use rand::random_range;

fn print(array: & [[i32; 4]; 4])
{
    for i in 0..4
    {
        for j in 0..4
        {
            print!("{:2} ", array[i][j]);
        }
        println!();
    }
    println!();
}

fn multiply(array_one: & [[i32; 4]; 4], array_two: & [[i32; 4]; 4]) -> [[i32; 4]; 4]
{
    let mut array_mul:[[i32; 4]; 4] = [[0; 4]; 4];
    
    for i in 0..4
    {
        for j in 0..4
        {
            array_mul[i][j] = 0;
            
            for k in 0..4
            {
                array_mul[i][j] = array_mul[i][j] + array_one[i][k] * array_two[k][j];
            }
        }
    }
    
    array_mul
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

    print(&multiply(&array_b, &array_a));
    print(&multiply(&array_a, &array_c));
    print(&multiply(&array_c, &array_a));
    
}
