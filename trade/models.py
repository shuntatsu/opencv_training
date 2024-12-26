from django.contrib.auth.models import User
from django.db import models

# 描画用
# Pricesモデル
class Price(models.Model):
    symbol = models.CharField(max_length=20)
    timestamp = models.TextField(primary_key=True)
    price = models.FloatField()

    class Meta:
        db_table = 'prices'

# OrderBookモデル
class OrderBook(models.Model):
    symbol = models.CharField(max_length=20)
    timestamp = models.TextField(primary_key=True)
    bids = models.TextField()
    asks = models.TextField()

    class Meta:
        db_table = 'order_book'

# Candlestickモデル
class Candlestick(models.Model):
    symbol = models.CharField(max_length=20)
    timeframe = models.CharField(max_length=10)
    timestamp = models.TextField(primary_key=True)
    open = models.FloatField()
    high = models.FloatField()
    low = models.FloatField()
    close = models.FloatField()

    class Meta:
        db_table = 'candlesticks'

# 基底クラス
class IndicatorBase(models.Model):
    symbol = models.CharField(max_length=20)
    timeframe = models.CharField(max_length=10)
    timestamp = models.TextField(primary_key=True)

    class Meta:
        abstract = True

# ボリンジャーバンド
class BollingerBands(IndicatorBase):
    upper_band = models.FloatField(null=True, blank=True)
    middle_band = models.FloatField(null=True, blank=True)
    lower_band = models.FloatField(null=True, blank=True)

    class Meta(IndicatorBase.Meta):
        db_table = 'bollinger_bands'

class MACD(IndicatorBase):
    macd_line = models.FloatField(null=True, blank=True)
    signal_line = models.FloatField(null=True, blank=True)
    histogram = models.FloatField(null=True, blank=True)

    class Meta(IndicatorBase.Meta):
        db_table = 'macd'

class DMI(IndicatorBase):
    adx = models.FloatField(null=True, blank=True)
    plus_di = models.FloatField(null=True, blank=True)
    minus_di = models.FloatField(null=True, blank=True)

    class Meta(IndicatorBase.Meta):
        db_table = 'dmi'

class RSI(IndicatorBase):
    rsi = models.FloatField(null=True, blank=True)

    class Meta(IndicatorBase.Meta):
        db_table = 'rsi'

# 確定申告用
# 取引データ
class Transaction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='transactions')
    date = models.DateTimeField()
    crypto_currency = models.CharField(max_length=25)
    transaction_type = models.CharField(max_length=10, choices=[('BUY', '購入'), ('SELL', '売却')])
    amount = models.DecimalField(max_digits=18, decimal_places=8)
    price = models.DecimalField(max_digits=18, decimal_places=4)
    purchase_fee = models.DecimalField(max_digits=24, decimal_places=8)
    sale_fee = models.DecimalField(max_digits=18, decimal_places=2, blank=True)

    def __str__(self):
        return f"{self.user.username} - {self.crypto_currency} {self.transaction_type} on {self.date}"

# 所持通貨
class CurrentHoldings(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='current_holdings')
    date = models.DateTimeField()
    crypto_currency = models.CharField(max_length=25)
    amount = models.DecimalField(max_digits=18, decimal_places=8)
    purchase_price = models.DecimalField(max_digits=24, decimal_places=8)

    def __str__(self):
        return f"{self.user.username} - {self.crypto_currency}"
    
# 月次報告
class MonthlyReport(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='monthly_reports')
    year = models.IntegerField()
    month = models.IntegerField()
    total_purchase = models.DecimalField(max_digits=18, decimal_places=2)
    total_sale = models.DecimalField(max_digits=18, decimal_places=2)
    total_profit_loss = models.DecimalField(max_digits=18, decimal_places=2)
    total_fee = models.DecimalField(max_digits=18, decimal_places=2)

    def __str__(self):
        return f"{self.user.username} - {self.year}年{self.month}月"
    
# 確定申告
class AnnualReport(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='annual_reports')
    year = models.IntegerField()
    total_profit_loss = models.DecimalField(max_digits=18, decimal_places=2)
    total_sale_fee = models.DecimalField(max_digits=18, decimal_places=2)
    taxable_income = models.DecimalField(max_digits=18, decimal_places=2)

    def __str__(self):
        return f"{self.user.username} - {self.year}年"