<h2><a href="https://leetcode.com/problems/rabbits-in-forest">Rabbits in Forest 🐰🌳</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>There is a forest with an unknown number of rabbits. We asked n rabbits <strong>&quot;How many rabbits have the same color as you?&quot;</strong> and collected the answers in an integer array <code>answers</code> where <code>answers[i]</code> is the answer of the <code>i<sup>th</sup></code> rabbit.</p>

<p>Given the array <code>answers</code>, return <em>the minimum number of rabbits that could be in the forest</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> answers = [1,1,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
The two rabbits that answered &quot;1&quot; could both be the same color, say red.
The rabbit that answered &quot;2&quot; can&#39;t be red or the answers would be inconsistent.
Say the rabbit that answered &quot;2&quot; was blue.
Then there should be 2 other blue rabbits in the forest that didn&#39;t answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn&#39;t.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> answers = [10,10,10]
<strong>Output:</strong> 11
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 &lt;= answers.length &lt;= 1000</code></li>
    <li><code>0 &lt;= answers[i] &lt; 1000</code></li>
</ul>

<hr>

<h3>الشرح بالبلدي كده 🇪🇬👇</h3>

<p>الحكاية وما فيها يا برنس الليالي 🌃، إن فيه غابة مليانة أرانب 🐰🐰، بس إحنا مش عارفين عددهم كام بالظبط. قمنا لمينا شوية أرانب منهم وسألنا كل واحد سؤال وجودي 🤔: "يا أرنوب يا جميل، فيه كام أرنب تاني في الغابة دي نفس لونك بالظبط؟" الأرانب ردت بشوية أرقام وادتهالنا في لستة اسمها <code>answers</code>.</p>

<p>المطلوب مننا بقى إيه؟ نكون محقق كونان 🕵️ ونعرف <strong>أقل عدد ممكن</strong> من الأرانب كلها يكون عايش في الغابة دي بناءً على الأجوبة اللي سمعناها.</p>

<p><strong>القاعدة اللي ماشيين عليها زي الألف ✔️:</strong></p>
<p>لو أرنب قالك "يا باشا أنا معايا <code>x</code> أرانب تانيين نفس لوني"، ده معناه فورًا إن الشلة بتاعته كلها (هو واللي زيه) عددهم بالظبط <code>x + 1</code>. يعني لو أرنب قالك 'فيه 2 تانيين زيي'، يبقى الشلة بتاعته كلها على بعض 3 (هو والاتنين التانيين). مش شلة كورة قدم هي! ⚽️ لأ دي شلة أرانب 🐇. وكل اللي في نفس الشلة (نفس اللون) لازم يقولوا نفس الرقم بالظبط، مفيش فصال!</p>

<p><strong>المثال التاني أبو عشرات ده (Example 2: <code>[10, 10, 10]</code>):</strong></p>
<p>ده بقى حكايته حكاية 🤣. تلات أرانب كل واحد فيهم قال "10". يبقى الشلة بتاعتهم كام واحد؟ بسيطة: <code>10 + 1 = 11</code> أرنب بالصلاة ع النبي 🙏. طب إزاي 3 بس اللي ردوا علينا؟ عادي جدًا يا كبير! ده معناه إن فيه <code>11 - 3 = 8</code> أرانب تانيين من نفس الشلة دي قاعدين بيشربوا شاي بالياسمين في حتة تانية في الغابة ☕️ ومحدش عبرهم بسؤال. المهم إن الشلة دي لازم يكون فيها 11 أرنب عشان الكلام يبقى منطقي. عشان كده أقل عدد ممكن من الأرانب في الحالة دي هو 11 أرنب بالتمام والكمال.</p>

<h3>الكود ده بيعمل إيه بقى؟ 🤔💻</h3>

<p>ده الكود البايثون اللي بيحل الليلة دي وهو متظبط ومية فل وعشرة:</p>
<pre><code class="language-python">
from math import ceil
from collections import Counter # متنساش دول فوق خالص يا نجم

class Solution(object):
    def numRabbits(self, answers):
        # 1. نعد كل إجابة اتكررت كام مرة (زي فرز الأصوات 😂)
        mp = Counter(answers) 
        # لو answers = [10, 10, 10] -> mp هيبقى {10: 3}

        ans = 0 # الحصالة اللي هنجمع فيها الأرانب 💰

        # 2. نلف على كل إجابة *مميزة* شفناها (الـ 10 مرة واحدة بس)
        for x in mp: 
            
            # عدد مرات تكرار الإجابة x (في مثالنا: mp[10] = 3)
            count_x = mp[x] 
            # حجم الشلة بتاعة اللي جاوبوا x (في مثالنا: 10 + 1 = 11)
            group_size = x + 1 

            # 3. الحسبة السحرية: نشوف محتاجين كام شلة بالظبط؟ 🤔
            # نقسم عدد اللي جاوبوا (count_x) على حجم الشلة (group_size)
            # ونقرب الناتج ده *لفوووووق* لأقرب رقم صحيح (ceil). 
            # ليه لفوق؟ عشان لو فضل أرنب يتيم لوحده 🥺، لازم نفتحله شلة كاملة جديدة!
            num_groups_needed = ceil(float(count_x) / group_size)

            # 4. نضيف للمجموع: عدد الشلل اللي محتاجينها * حجم الشلة الواحدة
            ans += num_groups_needed * group_size

        # 5. نرجع اللي جمعناه في الحصالة (الأرانب كلها 🥳)
        return int(ans) 
</code></pre>

<p><strong>شرح الكود خطوة بخطوة بالعامية الفلاحي الأصيلة:</strong></p>
<ol>
    <li><strong>الجرد والحصر 📋:</strong> أول حاجة بنعمل جرد للأجوبة اللي جاتلنا ونعد كل رقم اتكرر كام مرة باستخدام <code>Counter</code> (زي ما يكون بنعد غلة الأرض بالظبط! 😄). النتيجة بنحطها في <code>mp</code>.</li>
    <li><strong>الحصالة جاهزة 💰:</strong> بنجهز حصالة اسمها <code>ans</code> ونحط فيها صفر عشان نبدأ نجمع فيها الأرانب.</li>
    <li><strong>لفة على الأنواع 🔄:</strong> بنلف على كل نوع إجابة مميز موجود في <code>mp</code> (يعني لو الـ 10 اتكررت مليون مرة، بنبص عليها مرة واحدة بس كـ "نوع 10").</li>
    <li><strong>الحسبة الجبارة 🔥:</strong> لكل نوع إجابة <code>x</code>:
        <ul>
            <li>بنشوف النوع ده اتكرر كام مرة (`mp[x]`).</li>
            <li>بنعرف إن الشلة بتاعته حجمها <code>x + 1</code>.</li>
            <li>بنحسب بالمللي محتاجين كام شلة من الحجم ده عشان تكفي كل الأرانب اللي جاوبت <code>x</code>. بنستخدم <code>ceil</code> (التقريب لفوق) عشان نضمن إن مفيش أرنب يفضل من غير شلة، حتى لو هو لوحده.</li>
            <li>بنضرب عدد الشلل اللي محتاجينها ده في حجم الشلة الواحدة (`x + 1`).</li>
            <li>بنرمي الرقم اللي طلع ده في الحصالة <code>ans</code>.</li>
        </ul>
    </li>
    <li><strong>التسليم النهائي 🏁:</strong> بعد ما نخلص لف على كل أنواع الأجوبة، بنرجع الرقم اللي اتجمع في الحصالة <code>ans</code>. هو ده أقل عدد أرانب ممكن يكون في الغابة.</li>
</ol>

<p>كده المسألة بقت في جيبك الصغير يا كبير 😎. شرح وكود ومثال، كله تمام التمام! يلا خش على اللي بعده ورزع الحل ده في الـ README! 💪</p>
