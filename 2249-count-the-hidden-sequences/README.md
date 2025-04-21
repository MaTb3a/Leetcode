<h2><a href="https://leetcode.com/problems/count-the-hidden-sequences">2145. Count the Hidden Sequences</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].</p>
<p>You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.</p>
<p>For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.</p>
<p>[5, 6, 3, 7] is not possible since it contains an element greater than 6.</p>
<p>[1, 2, 3, 4] is not possible since the differences are not correct.</p>
<p>Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> differences = [1,-3,4], lower = 1, upper = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> The possible hidden sequences are:
- [3, 4, 1, 5]
- [4, 5, 2, 6]
Thus, we return 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> differences = [3,-4,5,1,-2], lower = -4, upper = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong> The possible hidden sequences are:
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
Thus, we return 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> differences = [4,-7,2], lower = 3, upper = 6
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no possible hidden sequences. Thus, we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>n == differences.length</code></li>
    <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>-10<sup>5</sup> &lt;= differences[i] &lt;= 10<sup>5</sup></code></li>
    <li><code>-10<sup>5</sup> &lt;= lower &lt;= upper &lt;= 10<sup>5</sup></code></li>
</ul>

<hr>

<h3>فهم المسألة 🤔</h3>

<p>المسألة ببساطة بتدينا مصفوفة اسمها <code>differences</code>. المصفوفة دي فيها الفروقات بين كل عنصرين ورا بعض في "سيكوينس" أو متتابعة تانية مخفية إحنا منعرفهاش. يعني لو السيكوينس المخفية دي اسمها <code>hidden</code>، فالمسألة بتقولنا إن <code>differences[i] = hidden[i + 1] - hidden[i]</code>.</p>
<p>لو مصفوفة <code>differences</code> طولها <code>n</code>، يبقى السيكوينس المخفية <code>hidden</code> طولها هيكون <code>n + 1</code>.</p>
<p>كمان بتدينا رقمين، <code>lower</code> و <code>upper</code>، ودول بيمثلوا أقل وأكبر قيمة ممكنة لأي عنصر جوه السيكوينس المخفية <code>hidden</code>. يعني كل الأرقام في <code>hidden</code> لازم تكون أكبر من أو تساوي <code>lower</code> وأصغر من أو تساوي <code>upper</code>.</p>
<p><strong>المطلوب إيه؟</strong> المطلوب مننا نحسب فيه كام سيكوينس مخفية <code>hidden</code> ممكنة تحقق كل الشروط دي. لو مفيش ولا واحدة ممكنة، نرجع صفر.</p>
<p><strong>مثال للتوضيح (Example 1):</strong> لو <code>differences = [1, -3, 4]</code> و <code>lower = 1</code> و <code>upper = 6</code>.
السيكوينس المخفية طولها 4.
زي ما المثال قال، <code>[3, 4, 1, 5]</code> ممكنة ليه؟
لأن الفروقات مظبوطة: (4-3=1)، (1-4=-3)، (5-1=4).
وكمان كل الأرقام (3, 4, 1, 5) بين 1 و 6.
وبرضه <code>[4, 5, 2, 6]</code> ممكنة لنفس الأسباب.
لكن <code>[5, 6, 3, 7]</code> مش ممكنة عشان فيها 7 وده أكبر من <code>upper=6</code>.
و <code>[1, 2, 3, 4]</code> مش ممكنة عشان الفروقات مش مظبوطة.</p>

<h3>الفكرة الأساسية للحل 💡</h3>

<p>أهم ملاحظة هنا هي: لو عرفنا <strong>أول عنصر</strong> في السيكوينس المخفية (<code>hidden[0]</code>)، نقدر نعرف باقي العناصر كلها! إزاي؟ باستخدام مصفوفة <code>differences</code>:</p>
<ul>
    <li><code>hidden[1] = hidden[0] + differences[0]</code></li>
    <li><code>hidden[2] = hidden[1] + differences[1] = hidden[0] + differences[0] + differences[1]</code></li>
    <li><code>hidden[k] = hidden[0] + sum(differences[0]...differences[k-1])</code></li>
</ul>
<p>يعني كل عنصر في السيكوينس المخفية هو عبارة عن أول عنصر (<code>hidden[0]</code>) زائد مجموع الفروقات اللي قبله.</p>
<p>خلينا نسمي مجموع الفروقات ده "المجموع التراكمي" (prefix sum). ممكن نحسب قيم المجموع التراكمي دي واحنا ماشيين. هنعتبر المجموع التراكمي عند البداية (قبل أول فرق) بصفر.</p>
<p>كل عنصر <code>hidden[k]</code> لازم يحقق الشرط: <code>lower <= hidden[k] <= upper</code>.</p>
<p>بالتعويض: <code>lower <= hidden[0] + prefix_sum[k] <= upper</code>.</p>
<p>إحنا عايزين نعرف إيه القيم الممكنة لـ <code>hidden[0]</code>. لو عدّلنا المتباينة دي عشان نجيب <code>hidden[0]</code> في طرف لوحدها:</p>
<p><code>lower - prefix_sum[k] <= hidden[0] <= upper - prefix_sum[k]</code></p>
<p>الشرط ده لازم يتحقق لكل قيم <code>k</code> (من 0 لحد <code>n</code>). ده معناه إن <code>hidden[0]</code> لازم تكون أكبر من أو تساوي أكبر قيمة من بين كل الـ <code>(lower - prefix_sum[k])</code>، وفي نفس الوقت أصغر من أو تساوي أصغر قيمة من بين كل الـ <code>(upper - prefix_sum[k])</code>.</p>

<p><strong>بطريقة تانية أبسط (وهي اللي الكود الأول بيستخدمها):</strong></p>
<p>تخيل إننا بدأنا السيكوينس بـ <code>hidden[0] = 0</code> مؤقتًا، وحسبنا باقي القيم بناءً على الفروقات. القيم دي هتبقى هي قيم المجموع التراكمي (<code>prefix_sum[k]</code>) اللي حسبناها فوق (مع <code>prefix_sum[0]=0</code>).</p>
<p>دلوقتي، خلينا نشوف أقل قيمة وصلتلها السيكوينس المؤقتة دي (<code>min_val_relative</code>) وأكبر قيمة وصلتلها (<code>max_val_relative</code>). الفرق بينهم (<code>max_val_relative - min_val_relative</code>) ده بيمثل الـ "مدى" (range) بتاع شكل السيكوينس بغض النظر عن نقطة بدايتها.</p>
<p>إحنا عايزين نلاقي قيمة حقيقية لـ <code>hidden[0]</code> بحيث لما نضيفها لكل قيم السيكوينس المؤقتة، تفضل كل القيم الجديدة بين <code>lower</code> و <code>upper</code>.</p>
<ul>
    <li>أقل قيمة في السيكوينس النهائية هتكون <code>hidden[0] + min_val_relative</code>. دي لازم تكون <code>>= lower</code>. يعني <code>hidden[0] >= lower - min_val_relative</code>.</li>
    <li>أكبر قيمة في السيكوينس النهائية هتكون <code>hidden[0] + max_val_relative</code>. دي لازم تكون <code><= upper</code>. يعني <code>hidden[0] <= upper - max_val_relative</code>.</li>
</ul>
<p>يبقى، قيم <code>hidden[0]</code> الممكنة محصورة بين <code>[lower - min_val_relative, upper - max_val_relative]</code>.</p>
<p>عدد القيم الصحيحة الممكنة في النطاق ده هو: <code>(upper - max_val_relative) - (lower - min_val_relative) + 1</code></p>
<p>وده بيساوي: <code>(upper - lower) - (max_val_relative - min_val_relative) + 1</code></p>
<p>الفرق <code>max_val_relative - min_val_relative</code> هو الـ "مدى" بتاع السيكوينس اللي حسبناه. خلينا نسميه <code>range_of_sums</code>. يبقى عدد السيكوينسات الممكنة هو <code>(upper - lower) - range_of_sums + 1</code>.</p>
<p><strong>شرط مهم:</strong> لو الـ <code>range_of_sums</code> ده أكبر من المدى المسموح بيه أصلًا (<code>upper - lower</code>)، يبقى مستحيل نلاقي سيكوينس تحقق الشروط، والناتج يكون 0. وكمان الناتج مينفعش يكون سالب، فأقل قيمة ليه هي 0.</p>
