#第 1部分： 基本概念 

## 1 Function Templates 第 1章 函数模板 

### 1．1 A First Look at Function Templates/初识函数模板 
- 1．1．1 Defining the Template/定义模板 
- 1．1．2 Using the Template/使用模板 
- 1．1．3 Two-Phase Translation/二阶段翻译 
### 1．2 Template Argument Deduction/模板参数推导 
### 1．3 Multiple Template Parameters/多模板参数 
- 1．3．1 Template Parameters for Return Types/返回类型的模板参数 
- 1．3．2 Deducing the Return Type/推导返回类型 
- 1．3．3 Return Type as CommonType/作为通用类型返回 
### 1．4 Default Template Arguments/缺省模板参数 
### 1．5 Overloading Function Templates/重载函数模板 
### 1．6 But，Shouldn’t We．．． /但是，难道我们不应该…？ 
- 1．6．1 Pass by Value or by Reference /按值传递还是按引用传递？ 
- 1．6．2 Why Not inline 为什么不用inline呢？ 
- 1．6．3 Why Not constexpr 为什么不用constexpr呢？ 
### 1．7 Summary/小结 

## 2 Class Template 第 2章 类模板 

### 2．1 Implementation of Class Template Stack/类模板Stack的实现 
- 2．1．1 Declaration of Class Templates/类模板声明 
- 2．1．2 Implementation of Member Functions/成员函数的实现 
### 2．2 Use of Class Template Stack/类模板Stack的使用 
### 2．3 Partial Usage of Class Templates/类模板的局部使用 
### 2．3．1 Concepts/概念 
### 2．4 Friends/友元 
### 2．5 Specializations of Class Templates/类模板特化 
### 2．6 Partial Specialization/偏特化 
### 2．7 Default Class Template Arguments/缺省类模板参数 
### 2．8 Type Aliases/类型别名 
### 2．9 Class Template Argument Deduction/类模板参数推导 
### 2．10 Templatized Aggregates/模板聚合 
### 2．11 Summary/小结 

## 3 Nontype Template Parameters 第3章 非类型模板参数 

### 3．1 Nontype Class Template Parameters/非类型类模板参数 
### 3．2 Nontype Function Template Parameters/非类型函数模板参数 
### 3．3 Restrictions for Nontype Template Parameters/非类型模板参数的限制 
### 3．4 Template Parameter Type auto/模板参数类型auto 
### 3．5 Summary/小结 

## 4 Variadic Templates第4章 可变参数模板 

### 4．1 Variadic Templates/可变参数模板 
- 4．1．1 Variadic Templates by Example/可变参数模板实例 
- 4．1．2 Overloading Variadic and Nonvariadic Templates/重载可变参数和非可变参数模板 
- 4．1．3 Operator sizeof/运算符sizeof 
### 4．2 Fold Expressions/折叠表达式 
### 4．3 Application of Variadic Templates /可变参数模板的应用 
### 4．4 Variadic Class Templates and Variadic Expressions/可变参数类模板和可变参数表达式 
- 4．4．1 Variadic Expressions/可变参数表达式 
- 4．4．2 Variadic Indices/可变参数指数 
- 4．4．3 Variadic Class Templates/可变参数类模板 
- 4．4．4 Variadic Deduction Guides/可变参数推导指南 
- 4．4．5 Variadic Base Classes and using/可变参数基类和using 
### 4．5 Summary/小结 

## 5 Tricky Basics 第5章 基础技术 

### 5．1 Keyword typename/关键字typename 
### 5．2 Zero Initialization/零初始化 
### 5．3 Using this->/ this->的使用 
### 5．4 Templates for Raw Arrays and String Literals/原始数组和字符串字面量模板 
### 5．5 Member Templates/成员模板 
- 5．5．1 The ．template Construct/构造．template 
- 5．5．2 Generic Lambdas and Member Templates/泛型Lambda与成员模板 
### 5．6 Variable Templates/变量模板 
### 5．7 Template Template Parameters/模板的模板参数 
### 5．8 Summary/小结 

## 6 Move Semantics and enable_if<> 第6章 移动语义与enable_if<> 

### 6．1 Perfect Forwarding/完美转发 
### 6．2 Special Member Function Templates/特殊的成员函数模板 
### 6．3 Disable Templates with enable_if<>/使用enable_if <>禁用模板 
### 6．4 Using enable_if<>/使用enable_if<> 
### 6．5 Using Concepts to Simplify enable_if<> Expressions/ 使用概念简化enable_if<>表达式 
### 6．6 Summary/小结 

## 7 By Value or by Reference 第7章 按值传递还是按引用传递？ 

### 7．1 Passing by Value/按值传递 
### 7．2 Passing by Reference/按引用传递 
- 7．2．1 Passing by Constant Reference/按常量引用调传递 
- 7．2．2 Passing by Nonconstant Reference/按非常量引用传递 
- 7．2．3 Passing by Forwarding Reference/按转发传递 
### 7．3 Using std：：ref()andstd：：cref()/std：：ref() 和std：：cref()的使用 
### 7．4 Dealing with String Literals and Raw Arrays/ 处理字符串字面量常量与原始数组 
### 7．4．1 Special Implementations for String Literals and Raw Arrays/ 字符串字面量常量和原始数组的特殊实现 
### 7．5 Dealing with Return Values/处理返回值 
### 7．6 Recommended Template Parameter Declarations/模板参数声明推荐 
### 7．7 Summary/小结 

## 8 Compile-Time Programming 第8章 编译时编程 

### 8．1 Template Meta programming/模板元编程 
### 8．2 Computing with constexpr/使用constexpr计算 
### 8．3 Execution Path Selection with Partial Specialization/局部特化的执行路径选择 
### 8．4 SFINAE(Substitution Failure Is Not An Error)/ SFINAE（替换失败并不是一种错误） 
- 8．4．1 Expression SFINAE with decltype/ 带有decltype 的SFINAE表达式 
### 8．5 Compile-Time if/编译时if 
### 8．6 Summary/小结 

## 9 Using Templates in Practice 第9章 在实战中使用模板 

### 9．1 The Inclusion Model/包含模型 
- 9．1．1 Linker Errors/链接器错误 
- 9．1．2 Templates in Header Files/头文件中的模板 
### 9．2 Templates and inline/模板和内联 
### 9．3 Precompiled Headers/预编译头文件 
### 9．4 Decoding the Error Novel/破译大篇幅错误信息 
### 9．5 Afternotes/本章后记 
### 9．6 Summary/小结 

## 10 Basic Template Terminology 第 10章 基本模板术语 

### 10．1“Class Template” or “Template Class” / “类模板”还是“模板类” 
### 10．2 Substitution ， Instantiation ， and Specialization/替换、实例化和特化 
### 10．3 Declarations versus Definitions/声明和定义 
- 10．3．1 Complete versus Incomplete Types/完全和不完全类型 
### 10．4 The One-Definition Rule/一处定义规则 
### 10．5 Template Arguments versus Template Parameters/模板实数和模板形参 
### 10．6 Summary/小结 

## 11 Generic Libraries 第 11章 泛型库 

### 11．1 Callables/ Callable 
- 11．1．1 Supporting Function Objects/支持函数对象 
- 11．1．2 Dealing with Member Functions and Additional Arguments/处理成员函数和附加实参 
- 11 ．1．3 Wrapping Function Calls/包装函数调用 
### 11．2 Other Utilities to Implement Generic Libraries/实现泛型库的其他实用程序 
- 11．2．1 Type Traits/ Type Traits 
- 11．2．2 std：：addressof()/std：：addressof() 
- 11．2．3 std：：declval()/std：：declval() 
### 11．3 Perfect Forwarding Temporaries/完美转发临时对象 
### 11．4 References as Template Parameters/引用为模板参数 
### 11．5 Defer Evaluations/延迟评估 
### 11．6 Things to Consider When Writing Generic Libraries/编写泛型库时需要考虑的事情 
### 11．7 Summary/小结 

# PartII： Templates in Depth 第二部分 深入模板 

## 12 Fundamentals in Depth深入模板基础 

### 12．1 Parameterized Declarations/参数化宣告 
- 12．1．1 Virtual Member Functions/虚成员函数 
- 12．1．2 Linkage of Templates/模板链接 
- 12．1．3 Primary Templates/主模板 
### 12．2 Template Parameters/模板形参 
- 12．2．1 Type Parameters/类型形参 
- 12．2．2 Nontype Parameters/非类型形参 
- 12．2．3 Template Template Parameters/模板的模板形参 
- 12．2．4 Template Parameter Packs/模板参数包 
- 12．2．5 Default Template Arguments/缺省模板实参 
### 12．3 Template Arguments/模板实参 
- 12．3．1 Function Template Arguments/函数模板实参 
- 12．3．2 Type Arguments/类型实参 
- 12．3．3 Nontype Arguments/非类型实参 
- 12．3．4 Template Template Arguments/模板的模板实参 
- 12．3．5 Equivalence/实参的等价性 
### 12．4 Variadic Templates/可变参数模板 
- 12．4．1 Pack Expansions/包扩展 
- 12．4．2 Where Can Pack Expansions Occur /在哪里进行包扩展？ 
- 12．4．3 Function Parameter Packs/函数的参数包 
- 12．4．4 Multiple and Nested Pack Expansions/多重和嵌套包扩展 
- 12．4．5 Zero-Length Pack Expansions/零长度包扩展 
- 12．4．6 Fold Expressions/折叠表达式 
### 12．5 Friends/友元 
- 12．5．1 Friend Classes of Class Templates/类模板的友元类 
- 12．5．2 Friend Functions of Class Templates /类模板的友元函数 
- 12．5．3 Friend Templates/友元模板 
### 12．6 Afternotes/本章后记 

## 13 Names in Templates 第 13章 模板中的名称 

### 13．1 Name Taxonomy/名称的分类 
### 13．2 Looking Up Names/名称的查找 
- 13．2．1 Argument-Dependent Lookup/参数依赖查找 （ADL） 
- 13．2．2 Argument-Dependent Lookup of Friend Declarations/友元声明的ADL 
- 13．2．3 Injected Class Names/注入式类名称 
- 13．2．4 Current Instantiations/当前实例化 
### 13．3 Parsing Templates/解析模板 
- 13．3．1 Context Sensitivity in Nontemplates/非模板的上下文敏感性 
- 13．3．2 Dependent Names of Types/类型的依赖名称 
- 13．3．3 Dependent Names of Templates/模板的依赖名称 
- 13．3．4 Dependent Names in Using Declarations/使用声明中的依赖名称 
- 13．3．5 ADL and Explicit Template Arguments/ADL和显式模板实参 
- 13．3．6 Dependent Expressions/依赖表达式 
- 13．3．7 Compiler Errors/编译器错误 
### 13．4 Inheritance and Class Templates/继承和类模板 
- 13．4．1 Nondependent Base Classes/非依赖型基类 
- 13．4．2 Dependent Base Classes/依赖型基类 
### 13．5 Afternotes/本章后记 

## 14 Instantiation 第 14章 实例化 

### 14．1 On-Demand Instantiation/ 按需实例化 
### 14．2 Lazy Instantiation/延迟实例化 
- 14．2．1 Partial and Full Instantiation/部分和全部实例化 
- 14．2．2 Instantiated Components/实例化组件 
### 14．3 The C++ Instantiation Model/C++实例化模型 
- 14．3．1 Two-Phase Lookup/二阶段查找 
- 14．3．2 Points of Instantiation/实例化点 
- 14．3．3 The Inclusion Model/包含模型 
### 14．4 Implementation Schemes/实现方案 
- 14．4．1 Greedy Instantiation/贪婪实例化 
- 14．4．2 Queried Instantiation/询问实例化 
- 14．4．3 Iterated Instantiation/迭代实例化 
### 14．5 Explicit Instantiation/显式实例化 
- 14．5．1 Manual Instantiation/手动实例化 
- 14．5．2 Explicit Instantiation Declarations/显式实例化声明 
### 14．6 Compile-Time if Statements/ 编译时if语句 
### 14．7 In the Standard Library/标准库 
### 14．8 Afternotes/本章后记 

## 15 Template Argument Deduction 第 15章 模板实参推导 

### 15．1 The Deduction Process/推导过程 
### 15．2 Deduced Contexts/推导上下文 
### 15．3 Special Deduction Situations/特殊的推导情况 
### 15．4 Initializer Lists/初始化列表 
### 15．5 Parameter Packs/形参包 
- 15．5．1 Literal Operator Templates/字面运算符模板 
### 15．6 Rvalue References/右值引用 
- 15．6．1 Reference Collapsing Rules/引用折叠原则 
- 15．6．2 Forwarding References/转发引用 
- 15．6．3 Perfect Forwarding/完美转发 
- 15．6．4 Deduction Surprises/推导的惊喜 
### 15．7 SFINAE(Substitution Failure Is Not An Error )/ 替换失败并不是错误 
- 15．7．1 Immediate Context/即时上下文 
### 15．8 Limitations of Deduction/推导的限制 
- 15．8．1 Allowable Argument Conversions/可接受的实参转换 
- 15．8．2 Class Template Arguments/类模板实参 
- 15．8．3 Default Call Arguments/缺省调用实参 
- 15．8．4 Exception Specifications/异常规范 
### 15．9 Explicit Function Template Arguments/显式函数模板实参 
### 15．10 Deduction from Initializers and Expressions/从初始化和表达式中推导 
- 15．10．1 The auto Type Specifier/ auto类型说明符 
- 15．10．2 Expressing the Type of an Expression with decltype/用 decltype表示表达式的类型 
- 15．10．3 decltype(auto)/ decltype(auto) 
- 15．10．4 Special Situations for auto Deduction/ auto推导的特殊情况 
- 15．10．5 Structured Bindings/结构化绑定 
- 15．10．6 Generic Lambdas/ 泛型Lambda表达式 
### 15．11 Alias Templates/别名模板 
### 15．12 Class Template Argument Deduction/类模板实参推导 
- 15．12．1 Deduction Guides/ 推导指南 
- 15．12．2 Implicit Deduction Guides/隐式推导指南 
- 15．12．3 Other Subtleties/其他细节 
### 15．13 Afternotes/本章后记 

## 16 Specialization and Overloading 特化和重载 

### 16．1 When“Generic Code” Doesn’t Quite Cut It/当“泛型代码”并不能很好地解决问题时 
- 16．1．1 Transparent Customization/ 透明自定义 
- 16．1．2 Semantic Transparency/语义透明度 
### 16．2 Overloading Function Templates/重载函数模板 
- 16．2．1 Signatures/签名 
- 16．2．2 Partial Ordering of Overloaded Function Templates/重载函数模板的偏序 
- 16．2．3 Formal Ordering Rules/正式的排序规则 
- 16．2．4 Templates and Nontemplates/模板和非模板 
- 16．2．5 Variadic Function Templates/可变参数函数模板 
### 16．3 Explicit Specialization/显式特化 
- 16．3．1 Full Class Template Specialization/全局类模板特化 
- 16．3．2 Full Function Template Specialization/全局函数模板特化 
- 16．3．3 Full Variable Template Specialization/全局可变模板特化 
- 16．3．4 Full Member Specialization/全局成员特化．． 
### 16．4 Partial Class Template Specialization/局部类模板特化 
### 16．5 Partial Variable Template Specialization/局部可变模板特化 
### 16．6 Afternotes/本章后记 

## 17 Future Directions 第 17章 未来发展方向 

### 17．1 Relaxed typename Rules/宽松的typename原则 
### 17．2 Generalized Nontype Template Parameters/广义非类型模板参数 
### 17．3 Partial Specialization of Function Templates/函数模板的局部特化 
### 17．4 Named Template Arguments/命名模板实参 
### 17．5 Overloaded Class Templates/重载类模板 
### 17．6 Deduction for Nonfinal Pack Expansions/中间包扩展的推导 
### 17．7 Regularization of void/void的规范化 
### 17．8 Type Checking for Templates/模板的类型检查 
### 17．9 Reflective Meta programming/反射元编程 
### 17．10 Pack Facilities/包管理工具 
### 17．11 Modules/模块 

# PartIII： Templates and Design 第3部分 模板和设计 

## 18 The Polymorphic Power of Templates 第 18章 模板的多态性 

### 18．1 Dynamic Polymorphism/动态多态性 
### 18．2 Static Polymorphism/静态多态性 
### 18．3 Dynamic versus Static Polymorphism/动态多态性与静态多态性 
### 18．4 Using Concepts/概念 
### 18．5 New Forms of Design Patterns/设计模式的新形式 
### 18．6 Generic Programming/泛型编程 
### 18．7 Afternotes/本章后记 

## 19 Implementing Traits 第 19章Trait的实现 
### 19．1 An Example ： Accumulating a Sequence/一个实例：累加一个序列 
- 19．1．1 Fixed Traits/Fixed Trait 
- 19．1．2 Value Traits/Value Trait 
- 19．1．3 Parameterized Traits/参数化Trait 
### 19．2 Traits versus Policies and Policy Classes/ Traits、Policy和Policy类 
- 19．2．1 Traits and Policies ： What’s the Difference / Traits和 Policy：区别在哪里？ 
- 19．2．2MemberTemplatesversusTemplate Template Parameters/成员模板与模板的模板参数 
### 19．2．3Combining Multiple Policies and/or Traits/组合多个policy和／或trait 
- 19．2．4 Accumulation with General Iterators/用一般迭代器累积 
### 19．3 Type Functions/类型函数 
- 19．3．1 Element Types/元素类型 
- 19．3．2 Transformation Traits/ Transformation Traits 
- 19．3．3 Predicate Traits/ Predicate Traits 
- 19．3．4 Result Type Traits/ Result Type Traits 
### 19．4 SFINAE-Based Traits/ 基于SFINAE的Trait 
- 19．4．1 SFINAE Out Function Overloads/ SFINAE功能过载 
- 19．4．2 SFINAE Out Partial Specializations/ SFINAE局部特化 
- 19．4．3 Using Generic Lambdas for SFINAE/为SFINAE使用泛型Lambda表达式 
- 19．4．4 SFINAE-Friendly Traits/ SFINAE友好的特征 
### 19．5 IsConvertibleT/IsConvertibleT 
### 19．6 Detecting Members/检查成员 
### 19．6．1 Detecting Member Types/检查成员类型 
- 19．6．2 Detecting Arbitrary Member Types/检查任意成员类型 
- 19．6．3 Detecting Nontype Members/检查非类型成员 
- 19．6．4 Using Generic Lambdas to Detect Members/使用泛型Lambda表达式检查成员 
### 19．7 Other Traits Techniques/其他Trait技术 
- 19．7．1 If-Then-Else/ If-Then-Else 
- 19．7．2 Detecting Nonthrowing Operations/检查不抛出异常的操作 
- 19．7．3 Traits Convenience/ Trait的便利性 
### 19．8 Type Classification/类型分类 
- 19．8．1 Determining Fundamental Types/确定基本类型 
- 19．8．2 Determining Compound Types/确定复合类型 
- 19．8．3 Identifying Function Types/识别函数类型 
- 19．8．4 Determining Class Types/确定类类型 
- 19．8．5 Determining Enumeration Types/确定枚举类型 
### 19．9 Policy Traits/ Policy Trait 
- 19．9．1 Read-Only Parameter Types/ 只读参数类型 
### 19．10 In the Standard Library/在标准库中 
### 19．11 Afternotes/本章后记 

## 20 Overloading on Type Properties 第 20章 类型属性上的重载 

### 20．1 Algorithm Specialization/算法特化 
### 20．2 Tag Dispatching/标签调度 
### 20．3 Enabling/Disabling Function Templates/启用/禁用函数模板 
- 20．3．1 Providing Multiple Specializations/提供多重特化 
- 20．3．2 Where Does the EnableIf Go / EnableIf在哪里运行？ 
- 20．3．3 Compile-Time if/编译时if 
- 20．3．4 Concepts/概念 
### 20．4 Class Specialization/类的特化 
- 20．4．1 Enabling/Disabling Class Templates/启用/禁用类模板 
- 20．4．2 Tag Dispatching for Class Templates/类模板标签调度 
### 20．5 Instantiation-Safe Templates/ 实例化安全的模板 
### 20．6 In the Standard Library/在标准库中 
### 20．7 Afternotes/本章后记 

## 21 Templates and Inheritance 第 21章 模板和继承 

### 21．1 The Empty Base Class Optimization(EBCO)/ 空白基类最优化 
- 21．1．1 Layout Principles/布局原则 
- 21．1．2 Members as Base Classes/成员作为基类 
### 21．2 The Curiously Recurring Template Pattern(CRTP)/ 奇异递归模板模式 
- 21．2．1 The Barton-Nackman Trick/ Barton-Nackman技巧 
- 21．2．2 Operator Implementations/操作符实现 
- 21．2．3 Facades/ 门面模式 
### 21．3 Mixins/ Mixin 
- 21．3．1 Curious Mixins/ 令人好奇的Mixin 
- 21．3．2 Parameterized Virtuality参数化的虚拟性 
### 21．4 Named Template Arguments/指定模板参数 
### 21．5 Afternotes/本章后记 

## 22 Bridging Static and Dynamic Polymorphism 第 22章 桥接静态和动态多态性 

### 22．1 Function Objects ， Pointers ， and std：：function<>/函数对象、指针和std：：function<> 
### 22．2 Generalized Function Pointers/广义函数指针 
### 22．3 Bridge Interface/桥接口 
### 22．4 Type Erasure/类型擦除 
### 22．5 Optional Bridging/可选桥接 
### 22．6 Performance Considerations/性能考虑 
### 22．7 Afternotes/本章后记 

## 23 Meta programming 第 23章 元编程 

### 23．1 The State of Modern C++ Meta programming/现代C++元编程的状态 
- 23．1．1 Value Meta programming 
- 23．1．2 Type Meta programming/类型元编 
- 23．1．3 Hybrid Meta programming/混合元编程 
- 23．1．4 Hybrid Meta programming for Unit Types/单元类型的混合元编程 
### 23．2 The Dimensions of Reflective Meta programming/反射元编程的维数 
### 23．3 The Cost of Recursive Instantiation/递归实例化的代价 
### 23．3．1 Tracking All Instantiations/跟踪所有实例 
### 23．4 Computational Completeness/计算完整性 
### 23．5 Recursive Instantiation versus Recursive Template Arguments/递归实例化与递归模板参数 
### 23．6Enumeration Values versus Static Constants/枚举值与静态常量 
### 23．7 Afternotes/本章后记 

## 24 Typelists 第 24章Typelist 

### 24．1 Anatomy of a Typelist/ Typelist解析 
### 24．2 Typelist Algorithms/ Typelist算法 
- 24．2．1 Indexing/索引 
- 24．2．2 Finding the Best Match/寻找最佳匹配 
- 24．2．3 Appending to a Typelist/添加Typelist 
- 24．2．4 Reversing a Typelist/反转Typelist 
- 24．2．5 Transforming a Typelist/转化Typelist 
- 24．2．6 Accumulating Typelists/累加Typelist 
- 24．2．7 Insertion Sort/插入排序 
### 24．3 Nontype Typelists/非类型Typelists 
- 24．3．1 Deducible Nontype Parameters/可推导的非类型参数 
### 24．4 Optimizing Algorithms with Pack Expansions/使用包扩展优化算法 
### 24．5 Cons-style Typelists/ Cons-style Typelist 
### 24．6 Afternotes/本章后记 

## 25 Tuples 第 25章 元组 

### 25．1 Basic Tuple Design/基本的元组设计 
- 25．1．1 Storage/存储 
- 25．1．2 Construction/结构 
### 25．2 Basic Tuple Operations/基本的元组操作 
- 25．2．1 Comparison/比较25．2．2 Output/输出 
### 25．3 Tuple Algorithms/元组算法 
- 25．3．1 Tuples as Typelists/元组作为Typelist 
- 25．3．2 Adding to and Removing from a Tuple/从元组中添加和移除 
- 25．3．3 Reversing a Tuple/反转一个元组 
- 25．3．4 Index Lists/索引列表 
- 25．3．5 Reversal with Index Lists/用索引列表进行反转 
- 25．3．6 Shuffle and Select/洗牌算法和选择算法 
### 25．4 Expanding Tuples/扩展元组 
### 25．5 Optimizing Tuple/优化元组 
- 25．5．1 Tuples and the EBCO/元组和EBCO 
- 25．5．2 Constant-time get()/常数时间的get() 
### 25．6 Tuple Subscript/元组下标 
### 25．7 Afternotes/本章后记 

## 26 Discriminated Unions 第 26章 可识别的联合 

### 26．1 Storage/存储 
### 26．2 Design/设计 
### 26．3 Value Query and Extraction/值查询与提取 
### 26．4 Element Initialization， Assignment and Destruction/元素初始化、赋值和销毁 
- 26．4．1 Initialization/初始化 
- 26．4．2 Destruction/销毁 
- 26．4．3 Assignment/赋值 
### 26．5 Visitors/访问 
- 26．5．1 Visit Result Type/访问结果类型 
- 26．5．2 Common Result Type/常见结果类型 
### 26．6 Variant Initialization an Assignment/变量初始化赋值 
### 26．7 Afternotes/本章后记 

## 27 Expression Templates 第 27章 表达式模板 

### 27．1 Temporaries and Split Loops/临时变量和分割循环 
### 27．2 Encoding Expressions in Template Arguments/在模板参数中编码表达式 
- 27．2．1 Operands of the Expression Templates/表达式模板的操作数 
- 27．2．2 The Array Type/ Array类型 
- 27．2．3 The Operators/运算符 
- 27．2．4 Review/回顾 
- 27．2．5 Expression Templates Assignments/表达式模板赋值 
### 27．3 Performance and Limitations of Expression Templates/表达式模板的性能与约束 
### 27．4 Afternotes/本章后记 

## 28 Debugging Templates 第 28章 调试模板 

### 28．1 Shallow Instantiation/浅式实例化 
### 28．2 Static Assertions/静态断言 
### 28．3 Archetypes/原型 
### 28．4 Tracers/跟踪程序 
### 28．5 Oracles/ Oracle 
### 28．6 Afternotes/本章后记 

# Appendixes/附录 

## A The One-Definition Rule 附录A 一处定义原则 

### A．1 Translation Units/翻译单元 
### A．2 Declarations and Definitions/声明和定义 
### A．3 The One-Definition Rule in Detail/一处定义原则的细节 
- A．3．1 One-per-Program Constraints/程序的一处定义约束 
- A．3．2 One-per-Translation Unit Constraints/翻译单元的一处定义约束 
- A．3．3 Cross-Translation Unit Equivalence Constraints/跨翻译单元的等价性约束 

## B Value Categories 附录B 值类别 

### B．1 Traditional Lvalues and Rvalues/传统的左值和右值 
### B．1．1 Lvalue-to-Rvalue Conversions/左值和右值转换 
### B．2 Value Categories Since C++11/ C++11的值类别 
- B．2．1 Temporary Materialization/临时实体化 
### B．3 Checking Value Categories with decltype/使用decltype检查值类别 
### B．4 Reference Types/引用类别 

## C Overload Resolution 附录C 重载解析 

### C．1 When Does Overload Resolution Kick In / 何时应用重载解析 
### C．2 Simplified Overload Resolution/简化的重载解析 
- C．2．1 The Implied Argument for Member Functions/成员函数的隐式参数 
- C．2．2 Refining the Perfect Match/对最佳匹配进行改进 
### C．3 Overloading Details/重载的细节 
- C．3．1 Prefer Nontemplates or More Specialized Templates/优先非模板还是更加专用的模板 
- C．3．2 Conversion Sequences/转义序列 
- C．3．3 Pointer Conversions/指针转换 
- C．3．4 Initializer Lists/初始化列表 
- C．3．5 Functors and Surrogate Functions/仿函数和代理函数 
- C．3．6 Other Overloading Contexts/其他重载情况 

## D Standard Type Utilities 附录D 标准类型实用程序 

### D．1 Using Type Traits/使用Type Traits 
- D．1．1 std：：integral_constant and std：：bool_constant/ std：：integral_constant和std：：bool_constant 
- D．1．2 Things You Should Know When Using Traits/使用Trait时应该知道的事 
### D．2 Primary and Composite Type Categories/主要类型和复合类型 
- D．2．1 Testing for the Primary Type Category/测试主要类型的类别 
- D．2．2 Test for Composite Type Categories/测试复合类型的类别 
### D．3 Type Properties and Operations/类型属性和操作 
- D．3．1 Other Type Properties/其他类型属性 
- D．3．2 Test for Specific Operations/测试具体操作 
- D．3．3 Relationships Between Types/类型之间的关系 
### D．4 Type Construction/类型结构 
### D．5 Other Traits/其他Trait 
### D．6 Combining Type Traits/组合Type Trait 
### D．7 Other Utilities/其他应用程序 

## E Concepts 附录E 概念 

### E．1 Using Concepts/使用概念 
### E．2 Defining Concepts/定义概念 
### E．3 Overloading on Constraints/重载约束 
- E．3．1 Constraint Subsumption/约束包含 
- E．3．2 Constraints and Tag Dispatching/约束和标签调度 
### E．4 Concept Tips/概念提示 
- E．4．1 Testing Concepts/测试概念 
- E．4．2 Concept Granularity/概念粒度 
- E．4．3 Binary Compatibility/二进制兼容性 

# Bibliography 文献目录 

# Forums/论坛 

# Books and WebSites/图书和网站 

# Glossary 术语 

# Index 索引
