/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    const st = [];

    for(let asteroid of asteroids) {
        if(asteroid > 0) {
            st.push(asteroid);
        }
        else {
            while(st.length > 0 && st[st.length-1] > 0) {
                const top = st[st.length - 1];

                if(top < -asteroid) {
                    st.pop(); // positive asteroid gets destroyed
                } else if(top === -asteroid) {
                    st.pop();
                    asteroid = 0; //both asteroid gets destroyed
                    break;
                } else {
                    asteroid = 0; // negative asteroid gets destroyed
                    break;
                }
            }

            if(asteroid !== 0) {
                st.push(asteroid);
            }
        }
    }

    return st;
};