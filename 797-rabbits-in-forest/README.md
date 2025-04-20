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

<h3>الشرح   </h3>

<p>تخيل يا معلم إنك دخلت غابة مليانة أرانب 🐰🐰 ألوانها مختلفة، بس انتا متعرفش عددهم كام بالظبط. قمت ماسك شوية أرانب كده وسألت كل واحد فيهم سؤال بسيط 🤔: "فيه كام أرنب تاني معاك في الغابة دي ليه نفس لونك بالظبط؟". كل أرنب رد عليك برقم. انتا بقى معاك لستة الأرقام اللي الأرانب ردت بيها دي (<code>answers</code>)، والمطلوب منك تخمن أقل عدد إجمالي ممكن من الأرانب يكون موجود في الغابة كلها.</p>

<p><strong>القاعدة الذهبية ✔️:</strong></p>
<ul>
    <li>لو أرنب قالك "أنا معايا <code>x</code> أرانب تانية نفس لوني"، ده معناه إن شِلّته (هو وكل اللي نفس لونه) عددهم على بعض بالظبط <code>x + 1</code>.</li>
    <li>كل الأرانب اللي من نفس اللون لازم يقولوا نفس الرقم بالظبط. مينفعش أرنب أحمر يقول "2" وأرنب أحمر تاني يقول "3". الكلام واحد! 🗣️</li>
</ul>

<p><strong>مثال عشان الدنيا تنور : <code>answers = [10, 10, 10]</code></strong></p>
<ul>
    <li><strong>إيه اللي حصل؟</strong> عندنا 3 أرانب، كل واحد فيهم فتح بقه وقال "10".</li>
    <li><strong>نفهم إيه؟</strong> طالما الأرنب قال "10"، يبقى هو تبع شلة عدد أفرادها <code>10 + 1 = 11</code> أرنب.</li>
    <li><strong>نستنتج إيه؟</strong> هل ممكن التلات أرانب دول يكونوا من نفس الشلة (نفس اللون، مثلاً أخضر 🟢)؟ أه طبعًا! لو هما نفس اللون الأخضر، يبقى شلتهم الخضرا دي لازم يكون عددها 11. طب إزاي اللي ردوا علينا 3 بس؟ عادي جدًا! ده معناه إن فيه <code>11 - 3 = 8</code> أرانب خضر تانيين مستخبيين في الغابة ورا الشجر كده 🌳 ومحدش سألهم حاجة.</li>
    <li><strong>الخلاصة؟</strong> أقل عدد ممكن من الأرانب في الحالة دي هو عدد أفراد الشلة الخضرا دي، اللي هو 11 أرنب. هو ده الناتج (Output: 11).</li>
</ul>
