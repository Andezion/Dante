use rand::random_range;

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

    for i in 0..4
    {
        for j in 0..4
        {
            print!("{:2} ", array_a[i][j] + array_b[i][j]);
        }
        println!();
    }

    println!();

    for i in 0..4
    {
        for j in 0..4
        {
            print!("{:2} ", array_a[i][j] - array_b[i][j]);
        }
        println!();
    }

    println!();

    for i in 0..4
    {
        for j in 0..4
        {
            print!("{:2} ", array_a[i][j] + array_b[i][j] + array_c[i][j]);
        }
        println!();
    }

    println!();

    for i in 0..4
    {
        for j in 0..4
        {
            print!("{:2} ", array_a[i][j] - array_b[i][j] - array_c[i][j]);
        }
        println!();
    }

    println!();

    for i in 0..4
    {
        for j in 0..4
        {
            print!("{:2} ", -1 * array_b[i][j]);
        }
        println!();
    }
}
